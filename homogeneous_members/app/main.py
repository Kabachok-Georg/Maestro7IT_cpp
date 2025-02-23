from fastapi import FastAPI, Request
from fastapi.responses import HTMLResponse
from fastapi.staticfiles import StaticFiles
from fastapi.templating import Jinja2Templates

app = FastAPI()

# Подключение статических файлов
app.mount("/static", StaticFiles(directory="app/static"), name="static")

# Подключение шаблонов
templates = Jinja2Templates(directory="app/templates")

# Подключение маршрутизаторов
from app.routers import theory, practice, glossary

app.include_router(theory.router)
app.include_router(practice.router)
app.include_router(glossary.router)

@app.get("/", response_class=HTMLResponse)
async def read_root(request: Request):
    return templates.TemplateResponse("index.html", {"request": request})
