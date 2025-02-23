# routers/theory.py

from fastapi import APIRouter, Request
from fastapi.responses import HTMLResponse
from fastapi.templating import Jinja2Templates

router = APIRouter()
templates = Jinja2Templates(directory="app/templates")

@router.get("/theory", response_class=HTMLResponse)
async def read_theory(request: Request):
    return templates.TemplateResponse("theory.html", {"request": request})
