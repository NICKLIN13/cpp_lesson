import { prefix } from '@fortawesome/free-solid-svg-icons';
import './App.css';
import TodoWrapper from './components/TodoWrapper';

import { useEffect } from 'react';
import { useState } from 'react'; // 這只是新增試試看能不能串連後端的

import axios from "axios";


const instance = axios.create({
	baseURL: "http://localhost:5001/api"
});

async function getTodos() {
	const res = await instance.get("/todos");
	console.log("res")
	console.log(res)
	return JSON.stringify(res.data);
}




function App() {
	const [todos, setTodos] = useState(); // 這只是新增試試看能不能串連後端的

	useEffect(() => {
		const init = async () => {
			const data = await getTodos();
			console.log("in useEffect");
			console.log(data);
			setTodos(data)
		}
		
		init()
	}, [])


	return (
		<div className="App">
			<TodoWrapper />
			<pre>{JSON.stringify(todos)}</pre> // 這只是新增試試看能不能串連後端的
    	</div>
	);
}

export default App;
