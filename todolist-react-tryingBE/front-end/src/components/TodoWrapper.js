import React from 'react'
import TodoForm from './TodoForm'
import { useState, useEffect } from 'react'
import { v4 as uuidv4 } from 'uuid';
import Todo from './Todo';
import EditTodoForm from './EditTodoForm';
import { 
	getTodos, 
	addTodo as add, 
	deleteTodo as del, 
	editTask as editTaskDescription,
	toggleComplete as toggle
} from '../utils/clients';



uuidv4();


const TodoWrapper = () => {

	const [todos, setTodos] = useState([])

  async function renderTodos() {
		const res = await getTodos();
		const todos_FE = res.data.map((todo_BE) => ({
      ...todo_BE,
      id: todo_BE._id}));
		setTodos(todos_FE);
	}

	useEffect(() => {	
		renderTodos();
	}, [])


	async function addTodo(todo, description) {

		await add(todo, description) // PUT AWAIT TO RENDER WITH ADDEDTODO IMMEDIATELY
		renderTodos()
		console.log(todos)
	}

	const toggleComplete = async (id) => {
    let completed;
		todos.forEach(todo => {
			if (todo.id === id) {
        console.log(todo);
				completed = todo.completed;
			}
			
		});
		await toggle(id, completed)
		renderTodos()
    console.log(todos)
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


	async function editTask (todo, id, description) {
		await editTaskDescription(todo, id, description);

		renderTodos();
		console.log(todos);
	}

	return (
		<div className='TodoWrapper'>
			<h1>Get Things Done!</h1>
			<TodoForm addTodo={addTodo}/>
			
			{todos.map((todo, index,) => (
			todo.isEditing ? (
				<EditTodoForm editTodo={editTask} todo={todo}/>
			) : (
				<Todo
          todo={todo}
				  toggleComplete={toggleComplete}
          deleteTodo={deleteTodo}
          editTodo={editTodo} 
        />
			)
			))}

		</div>
	)
}

export default TodoWrapper

