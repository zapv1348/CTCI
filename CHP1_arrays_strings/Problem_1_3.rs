
// this is kind of a weak sauce way to do this,
// doing it in place is slow because we have to shift the whole string down for every insertion (k shifts of n characters, where k is the number of spaces)
// a faster way would be to do the translation in reverse, so insert the back at the front and then put the characters for %20 replacing space
// in reverse order. Then reverse the whole string because that is pretty fast. It would be O(1.5n) = O(n) complexity.
// to do it in place, we could iterate through and count the number of spaces in the string. Then we start copying from the back going to the front
// using the same method as above. That would also be O(n) with O(1) space.
fn stringify_for_html(var: &mut String) {
    *var = var.replace(" ","%20");
}


fn main() {
    let mut test = String::from("yo what up how you be");
    stringify_for_html(&mut test);
    println!("{}", test);
}