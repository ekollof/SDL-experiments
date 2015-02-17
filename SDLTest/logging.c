#include "common.h"

void log_info(char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, fmt, ap);
	va_end(ap);

	return;
}

void log_debug(char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_DEBUG, fmt, ap);
	va_end(ap);

	return;
}

void log_error(char *fmt, ...) {
	va_list ap;

	va_start(ap, fmt);
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR, fmt, ap);
	va_end(ap);

	return;
}