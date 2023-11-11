
function addEventListener() {
    const headingInput = document.getElementById("heading-input");
    const executeButton = document.getElementById("change-heading");

    executeButton.addEventListener("click", function() {
        const title = headingInput.value;
        document.getElementById("heading").textContent = title;
    });
}

addEventListener();
