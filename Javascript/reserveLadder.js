// *
// * Given a string to be printed as follows:
// *
// * Example:
// * var str = "basic"
// *
// * Result:
// * B
// * aB
// * BaS
// * iSaB
// * BaSiC

function reserveLadder(str) {
    if (str.length % 2 == 0) {
    console.log("string characater must be odd");
    } else {
    let temp = "";
    for (let i = 0; i < str.length; i++) {
        if (i % 2 != 0) {
        temp += str[i];
        console.log(temp.split("").reverse().join(""));
        } else {
        temp += str[i].toUpperCase();
        console.log(temp);
        }
    }
 }

}

reserveLadder("hello")