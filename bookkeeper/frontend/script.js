<<<<<<< HEAD
=======
var count = 0;

const headingInput = document.getElementById("heading-input");
const executeButton = document.getElementById("change-heading");

var button = document.getElementById("counterbtn");
var countDisplay = document.getElementById("count");


function prettyDuck() {
    executeButton.addEventListener("click", function () {
        const title = headingInput.value;
        document.getElementById("heading").textContent = title;
    });

    button.addEventListener("click", function () {
        count++;
        countDisplay.textContent = count;
    })
};


prettyDuck();



>>>>>>> nick
