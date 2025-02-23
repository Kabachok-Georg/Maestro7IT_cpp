# routers/glossary.py

from fastapi import APIRouter, Request
from fastapi.responses import HTMLResponse
from fastapi.templating import Jinja2Templates

router = APIRouter()
templates = Jinja2Templates(directory="app/templates")

@router.get("/glossary", response_class=HTMLResponse)
async def read_glossary(request: Request):
    return templates.TemplateResponse("glossary.html", {"request": request})
