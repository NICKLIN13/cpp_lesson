import React from 'react'
import TodoForm from './TodoForm'
import { useState } from 'react'
import { v4 as uuidv4 } from 'uuid';
import Todo from './Todo';
import EditTodoForm from './EditTodoForm';
import { useEffect } from 'react';

uuidv4();





const TodoWrapper = () => {
	
	const LOCAL_STORAGE_KEY = 'todoApp.todos'
	
	const [todos, setTodos] = useState(() => {
		const storedTodos = JSON.parse(localStorage.getItem(LOCAL_STORAGE_KEY));
		if (storedTodos) {
			return storedTodos;
		} else {
			return [];
		}
	  });

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

	useEffect(() => { // for saving todos
		localStorage.setItem(LOCAL_STORAGE_KEY, JSON.stringify(todos))
		}, [todos])
	

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

