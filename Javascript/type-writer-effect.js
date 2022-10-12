document.addEventListener("DOMContentLoaded",function() {

    const dynamicContent = document.getElementById("dynamic-text");
    
    const phrases = ["Engineer...", "Human...", "Developer..."];
    
    let phraseIndex = 0;
    let letterIndex = 0;
    const typingSpeed = 200;
    const clearSpeed = 100;
    
    function printLetters(phrase) {
        if(letterIndex == phrase.length) {
            clearLetters();
        }
        else if(letterIndex < phrase.length) {
            dynamicContent.textContent += phrase.charAt(letterIndex);
            letterIndex++;
            setTimeout(function(){
                printLetters(phrase);
            },typingSpeed);
        }
    }
    
    function clearLetters() {
        if(letterIndex == -1) {
            phraseIndex = (phraseIndex+1) % phrases.length;
            letterIndex=0;
            printLetters(phrases[phraseIndex]);
        }
        else if(letterIndex > -1) {
            let updatedPhrase = "";
            for(var i=0; i<letterIndex; i++) {
                updatedPhrase += phrases[phraseIndex].charAt(i);
            }
            dynamicContent.textContent = updatedPhrase;
            letterIndex--;
            setTimeout(clearLetters,clearSpeed);
        }
    }
    
    printLetters(phrases[phraseIndex]);
})
