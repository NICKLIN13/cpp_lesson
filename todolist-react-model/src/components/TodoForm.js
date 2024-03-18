import React from 'react'
import { useState } from 'react'

const TodoForm = ({addTodo}) => {
    const [taskName, setTaskName] = useState("")

    const [description, setDescription] = useState("")

    const handleSubmit = e => {
        e.preventDefault();

        addTodo({taskName, description})
        setTaskName("")

    }



  return (
    <form className='TodoForm' onSubmit={handleSubmit}>
        <input type='text' className='todo-input' 
        value={taskName}
        placeholder='What is the task today?'
        onChange={(e) => setTaskName(e.target.value)} />
        <button type='submit' className='todo-btn'>Add Task</button><br/>
        
        <textarea
        type='text' id="todo-description-input"
				value={description}
        placeholder="description"
				tabindex="2"
        onChange={(e) => { setDescription(e.target.value); console.log(description);}} />
        
    </form>

  )
}

export default TodoForm
