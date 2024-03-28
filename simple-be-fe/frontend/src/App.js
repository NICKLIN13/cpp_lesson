import logo from './logo.svg';
import './App.css';
import axios from "axios";
import { useState } from "react";


const instance = axios.create({
  baseURL: "http://localhost:8000",
});

async function getTodos() {
  const res = await instance.get("/");
  console.log(res)
  return res.data;
}



function App() {
  const [todos, setTodos] = useState('default');

  return (
    <div className="App">
      <header className="App-header">
        <img src={logo} className="App-logo" alt="logo" />
        <p>
          Edit <code>src/App.js</code> and save to reload.
        </p>
        <a
          className="App-link"
          href="https://reactjs.org"
          target="_blank"
          rel="noopener noreferrer"
        >
          Learn React
        </a>
        {/* test for BACKEND_API_URL: getTodos */}
        <button onClick={async () => {
          const res = await getTodos();
          console.log(JSON.stringify(res));
          setTodos(JSON.stringify(res));
        }}>Get Todos</button>
        <p>Todos: {todos}</p> 

      </header>
    </div>
  );
}

export default App;
