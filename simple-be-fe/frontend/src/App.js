import logo from './logo.svg';
import './App.css';
import axios from "axios";
import { useState } from "react";

import { env } from "./env";

const instance = axios.create({
  baseURL: env.BACKEND_API_URL,
});

async function getTodos() {
  const response = await instance.get("/todos");
  return response.data;
}



function App() {
  const [todos, setTodos] = useState('');

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
          const todos = await getTodos();
          console.log(todos);
          setTodos(todos);
        }}>Get Todos</button>
        <p>Todos: {todos}</p> 

      </header>
    </div>
  );
}

export default App;
