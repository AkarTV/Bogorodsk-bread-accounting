# Bogorodsk-bread-accounting
This program is designed for calculating daily consumption of ingredients for a bakery.

Excel file "prices" is using as a database of prices of ingredients and products. 
User can change prices both in this file and in the program.

Excel file "table for test" is for a test this solution.

<h2>How to build:</h2>

1. Clone this project to your local machine.
2. Open this sollution in Qt Creator ('start_test.pro' file).
3. Build project (Ctrl+B)
4. In the same directory with this project Qt Creator creates "/the build-start-test-..." directory, insert there 'prices.xlsx' file from "/excel_tabels" directory in the project.
5. Run this project (Ctrl+R).

<h3>Interface example:</h3>
<p> On Start: </p>
<img src = "/images/on_start.png" width = "500">
<p> Report after excel table parcing: </p>
<img src = "/images/report.png" width ="500">
<a href="/report_example/Расход за 15 декабря 2020 г..pdf">Example of assembled PDF file</a>

<hr>

<h2>Third party:</h2>
To work with Excel files was used the library QXlsx from QtExcel developer. Link: https://github.com/QtExcel/QXlsx

This library is licensed under the MIT License:

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge , publish, distribute, sublicense, and / or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS SOFTWARE.
