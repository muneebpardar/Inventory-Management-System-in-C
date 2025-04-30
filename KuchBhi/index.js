const express = require('express');
const cors = require('cors');
const pool = require('./db')
require('dotenv').config();

const app = express();
app.use(cors());
app.use(express.json());



app.get('/', async(req, res) => {
    try {
        res.send('Welcome to the API');
    }
    catch (err) {        
        res.status(500).json({Error:err.message})
    }
});

app.get('/region', async(req, res) => {
    try {
        const result = await pool.query('SELECT * FROM regions');
        res.json(result.rows);
    }
    catch (err) {        
        res.status(500).json({Error:err.message})
    }
});

app.get('/country', async(req, res) => {
    try {
        const result = await pool.query('SELECT * FROM countries');
        res.json(result.rows);
    }
    catch (err) {        
        res.status(500).json({Error:err.message})
    }
});

app.get('/numberOfEmployee', async(req, res) => {
    try {
        const result = await pool.query('SELECT COUNT(EMPLOYEE_ID) FROM EMPLOYEES');
        res.json(result.rows);
    }
    catch (err) {        
        res.status(500).json({Error:err.message})
    }
});


const PORT = process.env.PORT;
app.listen(PORT, ()=>{
    console.log(`HOGAYAAA JANI...on PORT ${PORT}`)
});