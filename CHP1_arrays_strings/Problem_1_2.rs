use std::collections::HashMap;

trait IsContained {
    fn is_contained(&self, bigger_str: &str) -> bool;
}

struct Perm {
    map : HashMap<char,i32>,
    count : i32
}

impl Perm {
    fn new(var: &str) -> Perm {
        let mut tmp_map = HashMap::new();
        let mut tmp_count:i32 = 0;
        for i in var.chars() {
            tmp_count += 1;
            let tmp = tmp_map.entry(i).or_insert(0);
            *tmp += 1;
        }
        Perm {map: tmp_map, count: tmp_count}
    }
}

impl IsContained for Perm {
    // this isn't correct
    fn is_contained(&self, bigger_str: &str) -> bool{
        let mut cnt = 0;
        let mut cmp: HashMap<char, i32> = HashMap::new();
        for s in bigger_str.chars() {
            if self.map.contains_key(&s) {
                cnt += 1;
                let tmp = cmp.entry(s).or_insert(0);
                *tmp += 1;
            }
            else {
                cnt = 0;
                cmp.clear();
            };
            if cnt >= self.count {
                if cmp == self.map {return true}
            };
        }

        return false;
    }
}


fn main() {
    let word = Perm::new("sup");
    assert_eq!(word.is_contained("papus"), true);
    assert_eq!(word.is_contained("maperulups"), true);
    assert_eq!(word.is_contained("suitable"), false);
    assert_eq!(word.is_contained("pppapp"), false);
    println!("SUCCESS");
}


