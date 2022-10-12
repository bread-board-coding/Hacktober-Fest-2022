function countdown(fromNumber) {
    console.log(fromNumber);
    let nextNumber = fromNumber - 1;
    if (nextNumber > 0) {
        countdown(nextNumber);
    }
}
countdown(29);