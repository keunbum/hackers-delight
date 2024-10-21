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

fn dfs(v: usize, cnt: &mut usize, g: &Vec<Vec<usize>>, res: &mut Vec<usize>) {
  *cnt += 1;
  res[v] = *cnt;
  for &u in &g[v] {
    if res[u] == 0 {
      dfs(u, cnt, g, res);
    }
  }
}

fn main() {
  let mut scan = Scanner::default();
  let out = &mut BufWriter::new(stdout());
  let (n, m, st) = (scan.next::<usize>(), scan.next::<usize>(), scan.next::<usize>() - 1);
  let mut g = vec![vec![]; n];
  for _ in 0..m {
    let (x, y) = (scan.next::<usize>() - 1, scan.next::<usize>() - 1);
    g[x].push(y);
    g[y].push(x);
  }
  for i in 0..n {
    g[i].sort_unstable();
  }
  let mut res = vec![0; n];
  let mut cnt = 0;
  dfs(st, &mut cnt, &g, &mut res);
  for i in 0..n {
    writeln!(out, "{}", res[i]).ok();
  }
}