import React from 'react'
import { useState } from 'react'

const TodoForm = ({addTodo, addDetail}) => {
    const [value, setValue] = useState("")

    const [detail, setDetail] = useState("")

    const handleSubmit = e => {
        e.preventDefault();

        addTodo(value)
        setValue("")

        addDetail(detail)
        setDetail("")
    }



  return (
    <form className='TodoForm' onSubmit={handleSubmit}>
        <input type='text' className='todo-input' 
        value={value}
        placeholder='What is the task today?'
        onChange={(e) => setValue(e.target.value)} />
        <button type='submit' className='todo-btn'>Add Task</button><br/>
        
        <textarea
        type='text' id="todo-description-input"
				value={detail}
        placeholder="description"
				tabindex="2"
        onChange={(e) => setDetail(e.target.detail)} />
        
    </form>

  )
}

export default TodoForm
