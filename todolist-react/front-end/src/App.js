import './App.css';
import TodoWrapper from './components/TodoWrapper';

import { useEffect } from 'react';


function App() {

	useEffect(() => {
		async function getTodos() {
			const res = await fetch("/api/todos");
			const todos = await res.json();

			console.log(todos);
		}
		getTodos();
	}, [])


	return (
		<div className="App">
			<TodoWrapper />
    	</div>
	);
}

export default App;
