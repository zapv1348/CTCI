use std::collections::HashMap;

// palindrome permutation
// basically check if a string is a permutation of a palindrome
// the characteristic that's important about palindromes is that they have only one
// set of characters that are odd. If you find a two characters that occur in the string
// odd times, then the string isn't a permutation of a palindrome.
// we aren't checking if this palindrome is actually a real word or contains real words in the
// dictionary.

// I'm to lazy to deal with lower case
fn is_permutation_string(var: & String) -> bool {
    let mut m = HashMap::new();
    let mut b = false;
    for i in var.chars() {
        if i != ' ' {
            let j = m.entry(i).or_insert(0);
            *j += 1;
        }
    }
    println!("{:?}", m);
    for (_i,j) in m {
        if (j%2) == 1 {
            if b == true {return false}
            else {b = true};
        }
    }
    return true;
}

fn main() {
    assert_eq!(true, is_permutation_string(&"acot atc".to_string()));
    assert_eq!(false, is_permutation_string(&"mechakitten".to_string()));
}

