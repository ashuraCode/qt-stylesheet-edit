#include "highlighter.h"
#include "keywords.h"


Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    foreach (const QString &pattern, Keywords::MapOfProperties.keys()) {
        rule.pattern = QRegularExpression("\\b"+pattern+"\\b");
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    keywordFormat.setForeground(Qt::darkCyan);
    keywordFormat.setFontWeight(QFont::Medium);
    keywordFormat.setFontItalic(true);
    foreach (const QString &pattern, Keywords::ListOfPseudoStates) {
        rule.pattern = QRegularExpression(pattern+"\\b");
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    keywordFormat.setForeground(Qt::darkGray);
    keywordFormat.setFontWeight(QFont::Medium);
    keywordFormat.setFontItalic(true);
    foreach (const QString &pattern, Keywords::ListOfSubControls) {
        rule.pattern = QRegularExpression(pattern+"\\b");
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    widgetFormat.setFontWeight(QFont::Bold);
    widgetFormat.setForeground(Qt::darkMagenta);
    rule.pattern = QRegularExpression("\\bQ[A-Za-z]+\\b");
    rule.format = widgetFormat;
    highlightingRules.append(rule);

    nameWidgetFormat.setForeground(Qt::darkRed);
    rule.pattern = QRegularExpression("#\\w(\\w|\\d)*");
    rule.format = nameWidgetFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(Qt::gray);

    quotationFormat.setForeground(Qt::darkGreen);
    rule.pattern = QRegularExpression("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);

    commentStartExpression = QRegularExpression("/\\*");
    commentEndExpression = QRegularExpression("\\*/");
}

void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    setCurrentBlockState(0);

    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = text.indexOf(commentStartExpression);

    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength = 0;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + match.capturedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = text.indexOf(commentStartExpression, startIndex + commentLength);
    }
}
