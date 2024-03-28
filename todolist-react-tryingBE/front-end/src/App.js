import { prefix } from '@fortawesome/free-solid-svg-icons';
import './App.css';
import TodoWrapper from './components/TodoWrapper';

import { useEffect } from 'react';
import { useState } from 'react'; // 這只是新增試試看能不能串連後端的

import { getHello } from "./utils/clients"

function App() {
	const [hello, setHello] = useState("default"); // 這只是新增試試看能不能串連後端的

	useEffect(() => {
		const init = async () => {
			const res = await getHello();
			console.log("in useEffect");
			console.log(res);
			setHello(JSON.stringify(res.data))
		}
		
		init()
	}, [])


	return (
		<div className="App">
			<TodoWrapper />
			<pre>{hello}</pre> // 這只是新增試試看能不能串連後端的
    	</div>
	);
}

export default App;
