import { prefix } from '@fortawesome/free-solid-svg-icons';
import './App.css';
import TodoWrapper from './components/TodoWrapper';

import { useEffect } from 'react';
import { useState } from 'react'; // 這只是新增試試看能不能串連後端的


function App() {
	const [todos, setTodos] = useState([]); // 這只是新增試試看能不能串連後端的

	useEffect(() => {
		async function getTodos() {
			const res = await fetch("/api/todos");
			const todos = await res.json();

			setTodos(todos); // 這只是新增試試看能不能串連後端的
		}
		
		getTodos();
	}, [])


	return (
		<div className="App">
			<TodoWrapper />
			<pre>{JSON.stringify(todos, null, 2)}</pre> // 這只是新增試試看能不能串連後端的
    	</div>
	);
}

export default App;
