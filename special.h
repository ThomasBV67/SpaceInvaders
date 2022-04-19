#ifndef SPECIAL_H
#define SPECIAL_H

#include <QGraphicsPixmapItem>
#include <QEvent>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QObject>

class Special : public QGraphicsPixmapItem
{
public:
	enum { Type = UserType + 5 };
	int type() const override {
		return Type;
	}
	Enemy(QGraphicsScene* parent = nullptr);

private:

};



#endif	
