'''
class Room:
    def __init__(self, name, description):
        self.name = name
        self.description = description
        self.paths = {}

    def add_paths(self, paths):
        self.paths.update(paths)

    def move(self, direction):
        return self.paths.get(direction, None)

def show_instructions():
    print("""
    Текстовая приключенческая игра
    ==============================
    Комнаты соединены выходами.
    Введите 'quit' для выхода из игры.
    """)

def play_game():
    # Создаем комнаты
    living_room = Room("Гостиная", "Вы находитесь в гостиной. Здесь есть дверь на север и на восток.")
    kitchen = Room("Кухня", "Вы на кухне. Здесь пахнет вкусной едой. Дверь на запад.")
    bedroom = Room("Спальня", "Вы в спальне. Здесь есть уютная кровать. Дверь на юг.")

    # Соединяем комнаты
    living_room.add_paths({'север': bedroom, 'восток': kitchen})
    kitchen.add_paths({'запад': living_room})
    bedroom.add_paths({'юг': living_room})

    # Начинаем игру
    current_room = living_room
    show_instructions()

    while True:
        print("\nВы находитесь в " + current_room.name)
        print(current_room.description)

        command = input("> ").strip().lower()
        if command in ["север", "юг", "восток", "запад"]:
            next_room = current_room.move(command)
            if next_room:
                current_room = next_room
            else:
                print("Вы не можете идти в этом направлении.")
        elif command == "quit":
            print("Спасибо за игру!")
            break
        else:
            print("Неизвестная команда.")

if __name__ == "__main__":
    play_game()
'''

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
