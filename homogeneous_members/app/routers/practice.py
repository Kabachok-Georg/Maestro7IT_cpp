# routers/practice.py

from fastapi import APIRouter, Request
from fastapi.responses import HTMLResponse
from fastapi.templating import Jinja2Templates

router = APIRouter()
templates = Jinja2Templates(directory="app/templates")

@router.get("/practice", response_class=HTMLResponse)
async def read_practice(request: Request):
    return templates.TemplateResponse("practice.html", {"request": request})
