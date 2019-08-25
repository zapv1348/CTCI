
fn check_remove_char(word1: &String, word2: &String) {

}

fn check_insert_char(word1: &String, word2: &String) {

}

fn check_replace_char(word1: &String, word2: &String) {

}

fn is_single_edit_away(word1: &String, word2: &String) -> bool {
  let mut set = HashSet::new();
  for i in word2.chars() {
    set.insert(i);
  }

}
