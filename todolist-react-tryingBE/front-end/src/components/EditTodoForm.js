import React from 'react'
import { useState } from 'react'

const EditTodoForm = ({editTodo, task}) => {
    const [title, setTitle] = useState(task.task)

    const [description, setDescription] = useState(task.taskDescription) // DO I NEED THIS?  YES, I DO.

    const handleSubmit = e => {

      e.preventDefault();
      

      // Ensure that the user hasn't updated to blank
      if(title.trim() === '') {
        editTodo(task.task, task.id, description);
      } else {
        editTodo(title, task.id, description);
      }
      
      
    }
    
  return (
    <form className='TodoForm' onSubmit={handleSubmit}>
        <input type='text' className='title-input' 
        value={title}
        placeholder='Update Task'
        onChange={(e) => setTitle(e.target.value)} />

        <button type='submit' className='update-btn'>Update</button>

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
