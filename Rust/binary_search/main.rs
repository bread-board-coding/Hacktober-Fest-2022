
fn binary_search(array: &Vec<i32>, element: i32) -> i32 {
    let mut min = 0;
    let mut max = array.len() - 1;

    while min <= max {
        let mid = if max <= 0 { 0 } else {  min + (max - 1) / 2 };

        if array[mid] == element {
            return mid as i32;
        }
        
        if array[mid] < element {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }

    return -1;
}

fn main() {
    let v = vec![ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let result = binary_search(&v, 1);
    println!("found at index {}", result);
}
