import React from 'react'
import TodoForm from './TodoForm'
import { useState, useEffect } from 'react'
import { v4 as uuidv4 } from 'uuid';
import Todo from './Todo';
import EditTodoForm from './EditTodoForm';
import { getTodos } from '../utils/clients';



uuidv4();


const TodoWrapper = () => {

	const [todos, setTodos] = useState([])

	useEffect(() => {
		async function init() {
			const res = await getTodos();
			const todos = res.data;
			const todosFE = todos.map((todoBE) => ({...todoBE, "id": todoBE._id, task: todoBE.todo}));
			setTodos(todosFE);
		}

		
		init();
	}, [])

	const addTodo = (todo, taskDescription) => {
		setTodos([...todos, {id:uuidv4(), task: todo, completed: false, isEditing: false, taskDescription: taskDescription}])
		console.log(todos)
	}

	const toggleComplete = id => {
		setTodos(todos.map(todo => todo.id === id ? {...todo, completed : !todo.completed} : todo))
	}

	const deleteTodo = id => {
		setTodos(todos.filter(todo => todo.id !== id))
	}

	const editTodo = id => {
		setTodos(todos.map(todo => todo.id === id ? {...todo, isEditing: !todo.isEditing} : todo))
	} // toggle

	const editTask = (task, id, taskDescription) => {
		setTodos(todos.map(todo => todo.id === id ? {
				...todo, task, isEditing: !todo.isEditing, taskDescription: taskDescription } : todo))
	}

	return (
		<div className='TodoWrapper'>
			<h1>Get Things Done!</h1>
			<TodoForm addTodo={addTodo}/>
			
			{todos.map((todo, index,) => (
			todo.isEditing ? (
				<EditTodoForm editTodo={editTask} task={todo}/>
			) : (
				<Todo task={todo} key={index} 
				toggleComplete={toggleComplete} deleteTodo={deleteTodo} editTodo={editTodo} />
			)
			))}

		</div>
	)
}

export default TodoWrapper

