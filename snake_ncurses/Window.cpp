#include "Window.hpp"

void Window::clear()
{
	wclear(this->win);
}

void Window::startColor()
{
	start_color();
}

void Window::endWin()
{
	endwin();
}

void Window::addCh(int y, int x, char ch)
{
	mvwaddch(this->win, y, x, ch);
}

void Window::addStr(int y, int x, const char *str)
{
	mvwaddstr(this->win, y, x, str);
}

void Window::refresh()
{
	wrefresh(this->win);
}