import random
import json
import os

class Location:
    def __init__(self, name, description):
        self.name = name
        self.description = description
        self.paths = {}
        self.items = []
        self.enemies = []
        self.locked = False
        self.key_item = None
        self.npcs = []

    def add_paths(self, paths):
        self.paths.update(paths)

    def add_items(self, items):
        self.items.extend(items)

    def add_enemies(self, enemies):
        self.enemies.extend(enemies)

    def add_npcs(self, npcs):
        self.npcs.extend(npcs)

    def set_lock(self, key_item):
        self.locked = True
        self.key_item = key_item

    def move(self, direction):
        return self.paths.get(direction, None)

    def take_item(self, item):
        if item in self.items:
            self.items.remove(item)
            return True
        return False

    def unlock(self, item):
        if self.locked and item == self.key_item:
            self.locked = False
            return True
        return False

class Player:
    def __init__(self):
        self.health = 100
        self.inventory = []
        self.quests = []

    def take_damage(self, damage):
        self.health -= damage
        if self.health < 0:
            self.health = 0

    def heal(self, amount):
        self.health += amount
        if self.health > 100:
            self.health = 100

    def add_item(self, item):
        self.inventory.append(item)

    def remove_item(self, item):
        if item in self.inventory:
            self.inventory.remove(item)
            return True
        return False

    def add_quest(self, quest):
        self.quests.append(quest)

    def complete_quest(self, quest):
        if quest in self.quests:
            self.quests.remove(quest)
            return True
        return False

def show_instructions():
    print("""
    Тайна Затерянного Города
    ==========================
    Вы — известный археолог, который нашел древнюю карту, указывающую путь к затерянному городу.
    Ваша миссия — найти этот город и заполучить могущественный артефакт до того, как это сделают ваши конкуренты.
    Введите 'quit' для выхода из игры.
    Введите 'инвентарь', чтобы посмотреть ваши предметы.
    Введите 'здоровье', чтобы увидеть ваше состояние.
    Введите 'помощь', чтобы увидеть список команд.
    Введите 'квесты', чтобы увидеть ваши текущие задания.
    Введите 'сохранить', чтобы сохранить игру.
    Введите 'загрузить', чтобы загрузить игру.
    """)

def show_help():
    print("""
    Список команд:
    - север, юг, восток, запад: перемещение по локациям.
    - взять <предмет>: взять предмет из текущей локации.
    - использовать <предмет>: использовать предмет из инвентаря.
    - инвентарь: показать ваши предметы.
    - здоровье: показать ваше состояние здоровья.
    - квесты: показать ваши текущие задания.
    - помощь: показать этот список команд.
    - сохранить: сохранить текущий прогресс.
    - загрузить: загрузить сохраненный прогресс.
    - quit: выйти из игры.
    """)

def save_game(player, current_location):
    game_state = {
        "player": {
            "health": player.health,
            "inventory": player.inventory,
            "quests": player.quests
        },
        "current_location": current_location.name
    }
    with open("savegame.json", "w") as f:
        json.dump(game_state, f)
    print("Игра сохранена.")

def load_game():
    if not os.path.exists("savegame.json"):
        print("Сохранение не найдено.")
        return None, None
    with open("savegame.json", "r") as f:
        game_state = json.load(f)
    player = Player()
    player.health = game_state["player"]["health"]
    player.inventory = game_state["player"]["inventory"]
    player.quests = game_state["player"].get("quests", [])
    current_location_name = game_state["current_location"]
    return player, current_location_name

def fight(enemy):
    print(f"Вы встретили {enemy['name']}!")
    while player.health > 0 and enemy['health'] > 0:
        action = input("Введите 'атака' чтобы атаковать, 'использовать <предмет>' чтобы использовать предмет или 'бежать' чтобы попытаться сбежать: ").strip().lower()
        if action == "атака":
            damage = random.randint(10, 20)
            enemy['health'] -= damage
            print(f"Вы нанесли {damage} урона {enemy['name']}!")
            if enemy['health'] > 0:
                damage = random.randint(5, 15)
                player.take_damage(damage)
                print(f"{enemy['name']} нанес вам {damage} урона!")
            else:
                print(f"Вы победили {enemy['name']}!")
                return True
        elif action.startswith("использовать "):
            item = action.split(" ", 1)[1]
            if item in player.inventory:
                if item == "мачете":
                    damage = random.randint(20, 30)
                    enemy['health'] -= damage
                    print(f"Вы использовали {item} и нанесли {damage} урона {enemy['name']}!")
                elif item == "аптечка":
                    player.heal(20)
                    print(f"Вы использовали {item} и восстановили 20 здоровья!")
                    player.remove_item(item)
                else:
                    print(f"{item} нельзя использовать в бою.")
            else:
                print("У вас нет такого предмета.")
        elif action == "бежать":
            if random.random() < 0.5:
                print("Вам удалось сбежать!")
                return False
            else:
                print("Вы не смогли сбежать!")
                damage = random.randint(5, 15)
                player.take_damage(damage)
                print(f"{enemy['name']} нанес вам {damage} урона!")
        else:
            print("Неизвестная команда.")
    if player.health <= 0:
        print("Вы погибли...")
        return False
    return True

def random_event(location):
    events = [
        "Вы нашли аптечку!",
        "Вы споткнулись и потеряли 10 здоровья!",
        "Вы нашли древнюю монету!",
        "Вы услышали странные звуки, но ничего не произошло."
    ]
    event = random.choice(events)
    print(event)
    if event == "Вы нашли аптечку!":
        location.add_items(["аптечка"])
    elif event == "Вы споткнулись и потеряли 10 здоровья!":
        player.take_damage(10)
    elif event == "Вы нашли древнюю монету!":
        location.add_items(["древняя монета"])

def interact_npc(npc):
    print(f"{npc['name']}: {npc['dialog']}")
    if "quest" in npc:
        player.add_quest(npc["quest"])
        print(f"Вы получили новое задание: {npc['quest']}")

def play_game():
    global player
    player, current_location_name = load_game()
    if not player:
        player = Player()

    # Создаем локации
    office = Location("Офис", "Вы находитесь в своем офисе. На столе лежит древняя карта.")
    jungle_entrance = Location("Вход в джунгли", "Вы стоите у входа в джунгли. Дорога ведет на север.")
    jungle = Location("Джунгли", "Вы в густых джунглях. Здесь много растений и звуков диких животных.")
    ruins = Location("Руины", "Вы нашли древние руины. Здесь есть старые надписи на стенах.")
    lost_city = Location("Затерянный город", "Вы достигли затерянного города. Он окружен магическими барьерами.")
    temple = Location("Храм", "Вы в храме. Здесь хранится могущественный артефакт.")
    secret_room = Location("Секретная комната", "Вы нашли секретную комнату с сокровищами.")
    village = Location("Деревня", "Вы в небольшой деревне, где живут местные жители.")

    # Соединяем локации
    office.add_paths({'север': jungle_entrance})
    jungle_entrance.add_paths({'юг': office, 'север': jungle})
    jungle.add_paths({'юг': jungle_entrance, 'север': ruins, 'запад': village})
    ruins.add_paths({'юг': jungle, 'север': lost_city})
    lost_city.add_paths({'юг': ruins, 'север': temple})
    temple.add_paths({'восток': secret_room})
    village.add_paths({'восток': jungle})

    # Добавляем предметы
    office.add_items(["древняя карта"])
    jungle.add_items(["мачете"])
    ruins.add_items(["древний ключ"])
    temple.add_items(["артефакт"])
    secret_room.add_items(["сокровище"])
    village.add_items(["аптечка"])

    # Добавляем врагов
    jungle.add_enemies([{"name": "дикий зверь", "health": 50}])
    ruins.add_enemies([{"name": "древний страж", "health": 70}])
    lost_city.add_enemies([{"name": "магический страж", "health": 100}])
    temple.add_enemies([{"name": "храмовый страж", "health": 120}])

    # Добавляем NPC
    village.add_npcs([{"name": "Старейшина", "dialog": "Приветствую вас, путник. Я слышал, вы ищете затерянный город. Я могу помочь вам, если вы поможете нашей деревне.", "quest": "Помогите деревне"}])

    # Добавляем замки
    lost_city.set_lock("древний ключ")

    # Определяем текущую локацию
    current_location = office
    if current_location_name:
        for location in [office, jungle_entrance, jungle, ruins, lost_city, temple, secret_room, village]:
            if location.name == current_location_name:
                current_location = location
                break

    show_instructions()

    # Начало игры с диалогом
    if current_location == office and "древняя карта" in office.items:
        print("\nВы берете древнюю карту со стола и внимательно ее изучаете.")
        print("Внезапно звонит телефон. Это ваш старый друг и коллега, Джон.")
        print("Джон: Привет! Я слышал, ты нашел древнюю карту. Это удивительно! Но будь осторожен, я слышал, что другие археологи тоже ищут затерянный город. Ты должен опередить их!")
        print("Вы: Спасибо за предупреждение, Джон. Я немедленно отправляюсь в путь.")
        player.add_item("древняя карта")
        office.take_item("древняя карта")

    while True:
        print("\nВы находитесь в " + current_location.name)
        print(current_location.description)
        if current_location.items:
            print("Здесь вы видите: " + ", ".join(current_location.items))
        if current_location.enemies:
            for enemy in current_location.enemies:
                if not fight(enemy):
                    return
            current_location.enemies = []
        if current_location.npcs:
            for npc in current_location.npcs:
                interact_npc(npc)
            current_location.npcs = []

        # Случайное событие
        if random.random() < 0.2:
            random_event(current_location)

        command = input("> ").strip().lower()
        if command in ["север", "юг", "восток", "запад"]:
            next_location = current_location.move(command)
            if next_location:
                if next_location.locked:
                    item = input("Эта локация заперта. Введите название предмета, чтобы попытаться открыть её: ").strip().lower()
                    if next_location.unlock(item):
                        current_location = next_location
                    else:
                        print("Этот предмет не подходит.")
                else:
                    current_location = next_location
            else:
                print("Вы не можете идти в этом направлении.")
        elif command.startswith("взять "):
            item = command.split(" ", 1)[1]
            if current_location.take_item(item):
                player.add_item(item)
                print(f"Вы взяли {item}.")
            else:
                print("Здесь нет такого предмета.")
        elif command.startswith("использовать "):
            item = command.split(" ", 1)[1]
            if item in player.inventory:
                if item == "аптечка":
                    player.heal(20)
                    print(f"Вы использовали {item} и восстановили 20 здоровья!")
                    player.remove_item(item)
                else:
                    print(f"{item} нельзя использовать здесь.")
            else:
                print("У вас нет такого предмета.")
        elif command == "инвентарь":
            if player.inventory:
                print("В вашем инвентаре: " + ", ".join(player.inventory))
            else:
                print("Ваш инвентарь пуст.")
        elif command == "здоровье":
            print(f"Ваше здоровье: {player.health}")
        elif command == "квесты":
            if player.quests:
                print("Ваши текущие задания: " + ", ".join(player.quests))
            else:
                print("У вас нет текущих заданий.")
        elif command == "помощь":
            show_help()
        elif command == "сохранить":
            save_game(player, current_location)
        elif command == "загрузить":
            player, current_location_name = load_game()
            if player:
                for location in [office, jungle_entrance, jungle, ruins, lost_city, temple, secret_room, village]:
                    if location.name == current_location_name:
                        current_location = location
                        break
        elif command == "quit":
            print("Спасибо за игру!")
            break
        else:
            print("Неизвестная команда.")

        # Проверка условий победы
        if current_location == temple and "артефакт" in player.inventory:
            print("Поздравляем! Вы нашли артефакт и завершили игру!")
            break

if __name__ == "__main__":
    play_game()
