#include "highlighter.h"

Highlighter::Highlighter(QTextDocument* parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    QColor frontColorx(QRgb(0xE0E1E3));
    QColor bgColorLight(QRgb(0x455364));
    QColor bgColorDark(QRgb(0x19232D));

    // 散装的关键字，如 set conf chg
    QTextCharFormat keywordFormat;
    keywordFormat.setForeground(Qt::darkCyan);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bset"
        << "\\bconf"
        << "\\bchg"
        << "\\bdump"
        << "\\bcall";
    foreach(const QString & pattern, keywordPatterns)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    QTextCharFormat tarNumFormat;
    tarNumFormat.setForeground(Qt::darkMagenta);
    tarNumFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("((?<=\\bset)|(?<=\\bconf)|(?<=\\bchg)|(?<=\\bdump)|(?<=\\bcall))\\d*");
    rule.format = tarNumFormat;
    highlightingRules.append(rule);

    QTextCharFormat sharpFormat;
    sharpFormat.setForeground(bgColorLight);
    rule.pattern = QRegularExpression("#");
    rule.format = sharpFormat;
    highlightingRules.append(rule);

    QTextCharFormat dataNumFormat;
    dataNumFormat.setForeground(Qt::gray);
    dataNumFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegularExpression("(?<=#)[0-9.]*");
    rule.format = dataNumFormat;
    highlightingRules.append(rule);

    QTextCharFormat exclamationFormat;
    exclamationFormat.setForeground(bgColorLight);
    rule.pattern = QRegularExpression("!!!!");
    rule.format = exclamationFormat;
    highlightingRules.append(rule);

    QTextCharFormat titleFormat;
    titleFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression("Send\\$");
    rule.format = titleFormat;
    highlightingRules.append(rule);

    QTextCharFormat titleFormat2;
    titleFormat2.setForeground(Qt::darkRed);
    rule.pattern = QRegularExpression("Msg\\$");
    rule.format = titleFormat2;
    highlightingRules.append(rule);
}

void Highlighter::highlightBlock(const QString& text)
{
    foreach(const HighlightingRule & rule, highlightingRules)
    {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext())
        {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}
