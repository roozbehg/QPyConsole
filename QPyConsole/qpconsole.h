#ifndef QPCONSOLE_H
#define QPCONSOLE_H

#include <QPlainTextEdit>

class QPConsole : public QPlainTextEdit
{
  Q_OBJECT
public:
  explicit QPConsole(QWidget *parent = 0);
  void setPrefix(const QString &prefix);
  void setPrefixColor(const QColor &color);
  void setPrefixFont(const QFont &font);
  QString prefix() const { return mPrefix; }
  QColor prefixColor() const { return mPrefixColor; }
  QFont prefixFont() const { return mPrefixFont; }
  
signals:
  void command(QString cmd);
  
public slots:
  void print(QString str);
  void prepareCommandLine();
  
protected:
  bool inCommandLine() const;
  void processCommand();
  virtual void keyPressEvent(QKeyEvent *event);
  
  int mHistoryPos;
  QStringList mHistory;
  QString mPrefix;
  QColor mPrefixColor;
  QFont mPrefixFont;
  bool mCommandLineReady;
};

#endif // QPCONSOLE_H
