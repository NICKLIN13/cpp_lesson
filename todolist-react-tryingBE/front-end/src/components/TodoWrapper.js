import React from 'react'
import TodoForm from './TodoForm'
import { useState, useEffect } from 'react'
import { v4 as uuidv4 } from 'uuid';
import Todo from './Todo';
import EditTodoForm from './EditTodoForm';
import { getTodos, addTodo as add, deleteTodo as del, editTask as editTaskDescription } from '../utils/clients';



uuidv4();


const TodoWrapper = () => {

	const [todos, setTodos] = useState([])

    async function renderTodos() {
		const res = await getTodos();
		const todos = res.data;
		const todosFE = todos.map((todoBE) => ({...todoBE, "id": todoBE._id, task: todoBE.todo}));
		setTodos(todosFE);
	}

	useEffect(() => {	
		renderTodos();
	}, [])


	async function addTodo(todo, taskDescription) {
		// setTodos([...todos, {id:uuidv4(), task: todo, completed: false, isEditing: false, taskDescription: taskDescription}])
		await add(todo, taskDescription) // PUT AWAIT TO RENDER WITH ADDEDTODO IMMEDIATELY
		renderTodos()
		console.log(todos)
	}

	const toggleComplete = id => {
		setTodos(todos.map(todo => todo.id === id ? {...todo, completed : !todo.completed} : todo))
	}

	const deleteTodo = async (id) => {
		// setTodos(todos.filter(todo => todo.id !== id))

		await fetch(`api/todos/${id}`, {
			method : "DELETE"
		})

		// await del(id)
		renderTodos()
		console.log(todos)
	}

	const editTodo = id => {
		setTodos(todos.map(todo => todo.id === id ? {...todo, isEditing: !todo.isEditing} : todo))
	} // toggle


	async function editTask (task, id, taskDescription) {
		// setTodos(todos.map(todo => todo.id === id ? {
		// 		...todo, task, isEditing: !todo.isEditing, taskDescription: taskDescription } : todo))
		
		await editTaskDescription(task, id, taskDescription);

		renderTodos();
		console.log(todos);
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

