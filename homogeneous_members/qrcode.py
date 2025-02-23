import segno

def generate_qr_code(url, file_name, scale=20, dark='#000000', light='#FFFFFF'):
    """
    Генерирует QR-код для заданного URL и сохраняет его в файл.

    :param url: URL-адрес, который будет закодирован в QR-коде.
    :param file_name: Имя файла для сохранения изображения QR-кода.
    :param scale: Масштаб изображения QR-кода.
    :param dark: Цвет заполнения QR-кода.
    :param light: Фоновый цвет QR-кода.
    """
    try:
        # Создание QR-кода
        qr = segno.make_qr(url)

        # Сохранение изображения в файл
        qr.save(file_name, scale=scale, dark=dark, light=light)
        print(f"QR-код успешно сохранен в файл {file_name}")

    except Exception as e:
        print(f"Ошибка при генерации QR-кода: {e}")

if __name__ == "__main__":
    url = "https://www.example.com"  # Замените на нужный URL
    file_name = "qrcode_styled.png"
    generate_qr_code(url, file_name)
