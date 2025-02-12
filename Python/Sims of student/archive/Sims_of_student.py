import customtkinter as ctk
import tkinter as tk
from tkinter import messagebox
from PIL import Image
import random
import pickle
import os

class Student:
    def __init__(self):
        self.money = 4000
        self.satiety = 100
        self.sleep = 100
        self.mood = 100
        self.study_progress = 50
        self.days_left = 365
        self.health = 100

    def show_status(self):
        status = (f"Деньги: {self.money} руб\n"
                  f"Сытость: {self.satiety}%\n"
                  f"Сон: {self.sleep}%\n"
                  f"Настроение: {self.mood}%\n"
                  f"Успеваемость: {self.study_progress}%\n"
                  f"Здоровье: {self.health}%\n"
                  f"Дней до конца курса: {self.days_left}")
        return status

    def study(self):
        self.study_progress += 10
        self.mood -= 10
        self.sleep -= 10
        self.satiety -= 5
        self.health -= 5

    def work(self):
        self.money += 500
        self.mood -= 10
        self.sleep -= 15
        self.satiety -= 10
        self.health -= 5

    def eat(self):
        self.money -= 200
        self.satiety = 100
        self.health += 5

    def sleep_action(self):
        self.sleep = 100
        self.mood += 10
        self.health += 10

    def relax(self):
        self.mood = 100
        self.sleep += 10
        self.satiety -= 5
        self.health += 5

    def visit_doctor(self):
        self.money -= 300
        self.health = 100

    def is_alive(self):
        return (self.satiety > 0 and self.sleep > 0 and
                self.study_progress > 0 and self.health > 0)

    def update_status(self):
        if self.satiety < 50:
            self.mood -= 5
            self.study_progress -= 2
            self.health -= 5
        if self.sleep < 50:
            self.mood -= 5
            self.study_progress -= 2
            self.health -= 5
        if self.health < 50:
            self.mood -= 5
            self.study_progress -= 2

def random_event(player):
    event = random.randint(0, 5)
    if event == 0:
        player.health -= 20
        messagebox.showinfo("Событие", "Вы заболели [Потеряли 20% здоровья]")
    elif event == 1:
        player.money += 300
        messagebox.showinfo("Событие", "Вы получили стипендию [+300 руб]")
    elif event == 2:
        player.money -= 200
        messagebox.showinfo("Событие", "Вы потеряли кошелек [-200 руб]")
    elif event == 3:
        player.money += 100
        messagebox.showinfo("Событие", "Вы нашли деньги на улице [+100 руб]")
    elif event == 4:
        player.mood -= 10
        messagebox.showinfo("Событие", "Вы простудились [Потеряли 10% настроения]")
    elif event == 5:
        player.health -= 10
        messagebox.showinfo("Событие", "Вы попали под дождь и промокли [Потеряли 10% здоровья]")

def set_difficulty(player, difficulty):
    if difficulty == 1:
        player.money = 5000
        player.satiety = 120
        player.sleep = 120
        player.mood = 120
        player.health = 120
    elif difficulty == 2:
        player.money = 3000
        player.satiety = 100
        player.sleep = 100
        player.mood = 100
        player.health = 100
    elif difficulty == 3:
        player.money = 2000
        player.satiety = 80
        player.sleep = 80
        player.mood = 80
        player.health = 80
    else:
        messagebox.showinfo("Ошибка", "Неверный выбор уровня сложности. Установлен средний уровень.")
        player.money = 3000
        player.satiety = 100
        player.sleep = 100
        player.mood = 100
        player.health = 100

def save_game(player, filename):
    if not filename:
        filename = os.path.join(os.path.dirname(__file__), "savegame.pkl")  # Default filename in the project directory

    # Debug: Print the directory and full path to the file
    print(f"Debug: Directory - {os.path.dirname(__file__)}")
    print(f"Debug: Saving file to - {filename}")

    with open(filename, 'wb') as file:
        pickle.dump(player, file)
    messagebox.showinfo("Сохранение", "Игра сохранена успешно!")

def load_game(filename):
    if not filename:
        filename = os.path.join(os.path.dirname(__file__), "savegame.pkl")  # Default filename in the project directory

    # Debug: Print the directory and full path to the file
    print(f"Debug: Directory - {os.path.dirname(__file__)}")
    print(f"Debug: Loading file from - {filename}")

    try:
        with open(filename, 'rb') as file:
            player = pickle.load(file)
        messagebox.showinfo("Загрузка", "Игра загружена успешно!")
        return player
    except FileNotFoundError:
        messagebox.showerror("Ошибка", "Файл сохранения не найден. Пожалуйста, убедитесь, что файл находится в правильной директории.")
        return None

def play_game():
    ctk.set_appearance_mode("Dark")  # Modes: "System" (default), "Dark", "Light"
    ctk.set_default_color_theme("dark-blue")  # Themes: "blue" (default), "green", "dark-blue"

    root = ctk.CTk()
    root.title("Симулятор Студента")
    root.geometry("600x700")

    player = Student()

    def show_status():
        status_label.configure(text=player.show_status())

    def perform_action(action):
        if action == "study":
            player.study()
        elif action == "work":
            player.work()
        elif action == "eat":
            player.eat()
        elif action == "sleep":
            player.sleep_action()
        elif action == "relax":
            player.relax()
        elif action == "doctor":
            player.visit_doctor()
        elif action == "save":
            filename = save_entry.get()
            save_game(player, filename)
            return
        elif action == "exit":
            filename = save_entry.get()
            save_game(player, filename)
            root.quit()

        player.update_status()
        random_event(player)
        show_status()

        if not player.is_alive():
            messagebox.showinfo("Игра окончена", "Вы не смогли продолжить обучение. Игра окончена.")
            root.quit()
        elif player.days_left <= 0:
            if player.study_progress >= 100:
                messagebox.showinfo("Победа", "Поздравляем. Вы успешно завершили обучение!")
            else:
                messagebox.showinfo("Проигрыш", "К сожалению, вы не смогли завершить учебу. Попробуйте еще раз!")
            root.quit()
        else:
            player.days_left -= 1

    def load_game_action():
        nonlocal player
        filename = load_entry.get()
        if not os.path.isabs(filename):
            filename = os.path.join(os.path.dirname(__file__), filename)  # Ensure the filename is a full path
        loaded_player = load_game(filename)
        if loaded_player:
            player = loaded_player
            show_status()
            intro_frame.pack_forget()
            game_frame.pack(pady=20)

    def start_game():
        difficulty = difficulty_var.get()
        set_difficulty(player, difficulty)
        show_status()
        intro_frame.pack_forget()
        game_frame.pack(pady=20)

    # Load and display the student image
    image_path = os.path.join(os.path.dirname(__file__), "images", "student.png")
    print(f"Debug: Loading image from - {image_path}")
    try:
        img = ctk.CTkImage(Image.open(image_path), size=(200, 200))  # Use CTkImage to load the image
    except FileNotFoundError:
        messagebox.showerror("Ошибка", "Изображение 'student.png' не найдено. Пожалуйста, убедитесь, что файл находится в правильной директории.")
        img = None

    if img:
        img_label = ctk.CTkLabel(root, image=img, text="")
        img_label.image = img
        img_label.pack(pady=10)

    difficulty_var = ctk.IntVar()
    intro_frame = ctk.CTkFrame(root)
    intro_frame.pack(pady=20)

    difficulty_label = ctk.CTkLabel(intro_frame, text="Выберите уровень сложности:")
    difficulty_label.pack(pady=10)

    ctk.CTkRadioButton(intro_frame, text="Легкий", variable=difficulty_var, value=1).pack(anchor=ctk.W)
    ctk.CTkRadioButton(intro_frame, text="Средний", variable=difficulty_var, value=2).pack(anchor=ctk.W)
    ctk.CTkRadioButton(intro_frame, text="Тяжелый", variable=difficulty_var, value=3).pack(anchor=ctk.W)

    start_button = ctk.CTkButton(intro_frame, text="Начать игру", command=start_game)
    start_button.pack(pady=10)

    load_label = ctk.CTkLabel(intro_frame, text="Загрузить игру:")
    load_label.pack(pady=10)
    load_entry = ctk.CTkEntry(intro_frame)
    load_entry.pack()
    load_button = ctk.CTkButton(intro_frame, text="Загрузить", command=load_game_action)
    load_button.pack(pady=10)

    game_frame = ctk.CTkFrame(root)

    status_label = ctk.CTkLabel(game_frame, text="")
    status_label.pack(pady=10)

    action_frame = ctk.CTkFrame(game_frame)
    action_frame.pack(pady=10)

    ctk.CTkButton(action_frame, text="Учеба", command=lambda: perform_action("study")).grid(row=0, column=0, padx=5, pady=5)
    ctk.CTkButton(action_frame, text="Работа", command=lambda: perform_action("work")).grid(row=0, column=1, padx=5, pady=5)
    ctk.CTkButton(action_frame, text="Покушать", command=lambda: perform_action("eat")).grid(row=0, column=2, padx=5, pady=5)
    ctk.CTkButton(action_frame, text="Поспать", command=lambda: perform_action("sleep")).grid(row=1, column=0, padx=5, pady=5)
    ctk.CTkButton(action_frame, text="Отдыхать", command=lambda: perform_action("relax")).grid(row=1, column=1, padx=5, pady=5)
    ctk.CTkButton(action_frame, text="Посетить врача", command=lambda: perform_action("doctor")).grid(row=1, column=2, padx=5, pady=5)
    ctk.CTkButton(action_frame, text="Выйти", command=lambda: perform_action("exit")).grid(row=2, column=1, padx=5, pady=5)

    save_label = ctk.CTkLabel(game_frame, text="Сохранить игру:")
    save_label.pack(pady=10)
    save_entry = ctk.CTkEntry(game_frame)
    save_entry.pack()
    save_button = ctk.CTkButton(game_frame, text="Сохранить", command=lambda: perform_action("save"))
    save_button.pack(pady=10)

    root.mainloop()

if __name__ == "__main__":
    play_game()
