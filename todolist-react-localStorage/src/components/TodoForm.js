import React from 'react'
import { useState } from 'react'


const TodoForm = ({addTodo}) => {
    const [value, setValue] = useState("")

    const [description, setDescription] = useState("") // DO I NEED THIS?  YES, I DO.


    const handleSubmit = e => {
        e.preventDefault();

        addTodo(value, description)
        setValue("")
        setDescription("")
    }



  return (
    <form className='TodoForm' onSubmit={handleSubmit}>

        <input type='text' className='todo-input' 
        value={value}
        placeholder='What is the task today?'
        onChange={(e) => setValue(e.target.value)} />

        <button type='submit' className='todo-btn'  disabled={value.trim() === ''}>Add</button> <br/>
        
        <textarea
        id="todo-description-input"
        placeholder="description"
        tabIndex="2"
        value={description}
        onChange={(e) => setDescription(e.target.value)}
        ></textarea>

        

    </form>

  )
}

export default TodoForm
