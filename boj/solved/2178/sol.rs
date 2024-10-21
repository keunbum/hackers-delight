#![allow(unused_imports)]
use std::{
  cmp::{min, max},
  io::{BufWriter, stdin, stdout, Write},
  iter::FromIterator,
};

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
      self.buf = input.split_ascii_whitespace().rev().map(String::from).collect();
    }
  }
}

fn main() {
  let mut scan = Scanner::default();
  let out = &mut BufWriter::new(stdout());
  let (h, w) = (scan.next::<usize>(), scan.next::<usize>());
  let mut a = vec![vec![0; w]; h];
  for i in 0..h {
    let s = scan.next::<String>();
    let bytes = s.as_bytes();
    for j in 0..w {
      a[i][j] = (bytes[j] - b'0') as i32;
    }
  }
  let mut que = vec![(0, 0)];
  let mut b = 0;
  while b < que.len() {
    let (i, j) = que[b];
    for di in -1..=1 {
      for dj in -1..=1 {
        if di * di + dj * dj == 1 {
          let ni = i + di as usize;
          let nj = j + dj as usize;
          if ni < h && nj < w && a[ni][nj] == 1 {
            a[ni][nj] = a[i][j] + 1;
            que.push((ni, nj));
          }
        }
      }
    }
    b += 1
  }
  writeln!(out, "{}", a[h - 1][w - 1]).ok();
}