/* So Project MoD Extension
// Extension by DiR.X(Александр Шевченко)
// Нужные опции раскоментировать убрав //
// https://vk.com/multiplayer_of_dream
*/
#pragma once

//#define NEED_LAUNCH_COMAND_LAUNCHER //Ожидается ли для запуска комманда -launcher
#define SKIN_COUNTS 0x06 //Количество скинов в 16ричной системе(Нормально не работает)
#define MAX_PLAYER_SLOTS 0x40 //Количество слотов для игроков в 16ричной системе(Не тестилось по понятным причинам, сам больше 32 игроков набрать не могу)

#define FIX_SPACE_RESTRICTORS_FOR_DEDICATED // Фикс спейс рестрикторов на дедикейт сервере(Без этого оригинальный спавнер артов не работает).

#define NO_MONEY_LIMIT // Убираем ограничение в 1000000ру

#define FIX_SOC_SLOPES // Наклоны как в ТЧ?
#define FIX_BOLT_AND_PDA_SPAWN // Спавн болтов / ПДА (Болт удаляется при покупке-продаже нужно фиксить, место знаю, нужна врезка)
#define ACTIVE_BOLT_KEY // Активирует кнопку болта
#define ACTIVE_PDA_AND_DETECTOR_KEY //Фикс Кнопок детектора и ПДА
#define HIDE_WEAPON_ON_PRESS_ACTIVE_BUT // Прячем оружие по нажатию на кнопку активной пушки.

#define VODKA_EFFECT // Эффект водки
#define NEED_SATIETY // Голод 
#define OVERWEIGHT_FIX // Ограничение веса

#define RELOAD_CAMERA // Эффект камеры при перезарядке


#define NPC_INFO_ON_CROSHAIR //Подсветка НПС на перекрестье.
//#define WEAPON_AMMO_INFO //Добавляет к описанию оружия используемые патроны.
#define FIX_AF_PARTICLE //Исправляет партиклы в ногах при ношении артефакта(Не Тестил)
//#define ACTOR_SINGLE_MINI_MAP_ICO //Точка актора в пда как в сингле(Не Тестил)

#define INV_BOX_FIX // Inv Box Ящики для обыска
//#define TALK_FIX // TALK Работает не корректно
#define DEADBODY_INV_FIX // Deadbody INV Обыск трупов(Вроде работает но особо не тестил)
#define PDA_FIX // АНЛОК ПДА, И ЗАДАНИЙ

#define NEED_CLIENT_BIND //Бинд на клиентах
