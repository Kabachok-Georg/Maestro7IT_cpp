from fastapi import FastAPI
from fastapi.responses import HTMLResponse

app = FastAPI()

@app.get("/", response_class=HTMLResponse)
async def read_root():
    html_content = """
    <html>
        <head>
            <title>Образовательная платформа</title>
            <style>
                body { font-family: Arial, sans-serif; }
                header, footer { background: #007BFF; color: white; text-align: center; padding: 1rem; }
                nav ul { list-style: none; padding: 0; }
                nav ul li { display: inline; margin: 0 10px; }
                nav ul li a { color: white; text-decoration: none; }
                main { padding: 20px; }
                .course { border: 1px solid #ddd; padding: 20px; margin-bottom: 20px; border-radius: 5px; }
                .progress-bar { height: 20px; background: #007BFF; border-radius: 5px; }
            </style>
        </head>
        <body>
            <header>
                <h1>Образовательная платформа</h1>
                <nav>
                    <ul>
                        <li><a href="#theory">Теория</a></li>
                        <li><a href="#practice">Практика</a></li>
                    </ul>
                </nav>
            </header>
            <main>
                <section id="theory">
                    <h2>Теория</h2>
                    <p>Однородные члены предложения — это члены предложения, которые отвечают на один и тот же вопрос и выполняют одинаковую синтаксическую функцию. Они соединяются между собой с помощью союзов, таких как "и", "или", "но".</p>
                    <p>Пример: "Я купил яблоки, бананы и апельсины."</p>
                </section>
                <section id="practice">
                    <h2>Практика</h2>
                    <div class="exercise">
                        <p>Упражнение 1: Найдите однородные члены в предложении.</p>
                        <textarea placeholder="Введите предложение здесь..."></textarea>
                        <button onclick="checkSentence()">Проверить</button>
                        <p id="result"></p>
                    </div>
                </section>
            </main>
            <footer>
                <p>&copy; 2023 Образовательная платформа</p>
            </footer>
            <script>
                function checkSentence() {
                    const sentence = document.querySelector('textarea').value;
                    // Здесь можно добавить логику для проверки предложения
                    document.getElementById('result').innerText = `Вы ввели: ${sentence}`;
                }
            </script>
        </body>
    </html>
    """
    return HTMLResponse(content=html_content, status_code=200)
