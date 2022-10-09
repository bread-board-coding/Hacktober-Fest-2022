fn bubble_sort(array: &mut Vec<i32>) {
    let mut aux: i32;

    let mut i: usize = 1;
    while i < array.len() {
        let mut j: usize = 1;
        while j <= array.len() - 1 {
            if array[j - 1] > array[j] {
                aux = array[j - 1];
                array[j - 1] = array[j];
                array[j] = aux;
            }
            j += 1;
        }

        i += 1;
    }
}

fn main() {
    let mut v = vec![ 2, 3, 5, 7, 6, 1, 4 ];
    bubble_sort(&mut v);
    
    println!("sorted v {:?}", v);
}
