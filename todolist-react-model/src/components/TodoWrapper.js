import React from 'react'
import TodoForm from './TodoForm'
import { useState } from 'react'
import { v4 as uuidv4 } from 'uuid';
import Todo from './Todo';
import EditTodoForm from './EditTodoForm';

uuidv4();


const TodoWrapper = () => {

	const [todos, setTodos] = useState([])

	const [description, setDescription] = useState([])

	const addTodo = todo => {
		setTodos([...todos, {id:uuidv4(), task: todo, completed: false, isEditing: false}])
		console.log(todos)
	}

	const addDetail = detail => {
		setDescription([...description, {id: uuidv4(), task: detail}])
	}

	const toggleComplete = id => {
		setTodos(todos.map(todo => todo.id === id ? {...todo, completed : !todo.completed} : todo))
	}

	const deleteTodo = id => {
		setTodos(todos.filter(todo => todo.id !== id))
	}

	const editTodo = id => {
		setTodos(todos.map(todo => todo.id === id ? {...todo, isEditing: !todo.isEditing} : todo))
	}

	const editTask = (task, id) => {
		setTodos(todos.map(todo => todo.id === id ? {
				...todo, task, isEditing: !todo.isEditing } : todo))
	}

	return (
		<div className='TodoWrapper'>
			<h1>Get Things Done!</h1>
			<TodoForm addTodo={addTodo} addDetail={addDetail}/>

			{todos.map((todo, index, detail) => (
			todo.isEditing ? (
				<EditTodoForm editTodo={editTask} task={todo}/>
			) : (
				<Todo task={todo} key={index} 
				toggleComplete={toggleComplete} deleteTodo={deleteTodo} editTodo={editTodo}
				detail={detail}/>
			)
			))}



		</div>
	)
}

export default TodoWrapper
