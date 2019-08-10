
fn get_magic_elements(arr: Vec<usize>) -> Vec<usize>{
    let a = arr.iter().
                enumerate().
                filter(|x| (*x).0 == *((*x).1)).
                map(|(a,_b)| a).
                collect();
    return a;
}

fn main() {
    let b = vec![0,1,3,2,4,6,5,7];
    let c = get_magic_elements(b);
    println!("ret {:?}", c);   
}