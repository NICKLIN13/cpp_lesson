"use client"
var count = 0;




let title = "HELLO!";


function MyButton() {
  return (
    <>
      <button>{title}</button>
    </>
  );
}

export default function Home() {
  return (
    <>
      <link rel="stylesheet" href="style.css" />
      <h1 id="heading">{title}</h1>
      <div>
        <button onClick={
          () => {
            title = "good bye"
        }
        } id="change-heading" tabindex="3">execute</button>
        <input type="text" id="heading-input" placeholder="new heading" tabindex="1" />
      </div>

      <div>
        <button id="counterbtn" tabindex="3">counter: <span id="count">0</span></button>
      </div>

    </>
  )
}
