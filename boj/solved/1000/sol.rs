#![allow(unused_imports)]
use std::cmp::{min,max};
use std::io::{BufWriter, stdin, stdout, Write};
use std::iter::FromIterator;
 
#[derive(Default)]
struct Scanner {
  buf: Vec<String>
}

impl Scanner {
  fn next<T: std::str::FromStr>(&mut self) -> T {
    loop {
      if let Some(token) = self.buf.pop() {
        return token.parse().ok().expect("Failed parse");
      }
      let mut input = String::new();
      stdin().read_line(&mut input).expect("Failed read");
      self.buf = input.split_whitespace().rev().map(String::from).collect();
    }
  }
}

fn main() {
  let mut scan = Scanner::default();
  let out = &mut BufWriter::new(stdout());
  let a = scan.next::<u32>();
  let b = scan.next::<u32>();
  writeln!(out, "{}", a + b).ok();
}