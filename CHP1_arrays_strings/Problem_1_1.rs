use std::collections::HashMap;

fn is_unique(s: &str) -> bool {
  let mut count = HashMap::new();
  for a in s.chars() {
    if count.contains_key(&a) {return false}
    else {count.insert(a, 1)};
  }
  return true;
}

fn main() {
  assert_eq!(is_unique("sup"), true);
  assert_eq!(is_unique("yoooo"), false);
  println!("success");
}
