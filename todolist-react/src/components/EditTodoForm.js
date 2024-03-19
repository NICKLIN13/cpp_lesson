import React from 'react'
import { useState } from 'react'

const EditTodoForm = ({editTodo, task}) => {
    const [value, setValue] = useState(task.task)

    const [description, setDescription] = useState(task.taskDescription) // DO I NEED THIS?  YES, I DO.

    const handleSubmit = e => {
        e.preventDefault();

        editTodo(value, task.id, description);

    }
    
  return (
    <form className='TodoForm' onSubmit={handleSubmit}>
        <input type='text' className='todo-input' 
        value={value}
        placeholder='Update Task'
        onChange={(e) => setValue(e.target.value)} />

        <button type='submit' className='todo-btn'>Update</button>

        <textarea
        id="todo-description-input"
        placeholder="edit description"
        tabindex="2"
        value={description}
        onChange={(e) => setDescription(e.target.value)}
        ></textarea>



    </form>
    

  )
}

export default EditTodoForm
