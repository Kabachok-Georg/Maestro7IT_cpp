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
