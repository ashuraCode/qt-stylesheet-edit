#include "keywords.h"


QVector<QString> Keywords::ListOfStylableWidgets {
    "QAbstractScrollArea"
   , "QCheckBox"
   , "QColumnView"
   , "QComboBox"
   , "QDateEdit"
   , "QDateTimeEdit"
   , "QDialog"
   , "QDialogButtonBox"
   , "QDockWidget"
   , "QDoubleSpinBox"
   , "QFrame"
   , "QGroupBox"
   , "QHeaderView"
   , "QLabel"
   , "QLineEdit"
   , "QListView"
   , "QListWidget"
   , "QMainWindow"
   , "QMenu"
   , "QMenuBar"
   , "QMessageBox"
   , "QProgressBar"
   , "QPushButton"
   , "QRadioButton"
   , "QScrollBar"
   , "QSizeGrip"
   , "QSlider"
   , "QSpinBox"
   , "QSplitter"
   , "QStatusBar"
   , "QTabBar"
   , "QTabWidget"
   , "QTableView"
   , "QTableWidget"
   , "QTextEdit"
   , "QTimeEdit"
   , "QToolBar"
   , "QToolButton"
   , "QToolBox"
   , "QToolTip"
   , "QTreeView"
   , "QTreeWidget"
   , "QWidget"
};

QMap<QString, QString> Keywords::MapOfProperties {
    { "alternate-background-color", "Brush" }
    , { "background", "Background" }
    , { "background-color", "Brush" }
    , { "background-image", "Url" }
    , { "background-repeat", "Repeat" }
    , { "background-position", "Alignment" }
    , { "background-attachment", "Attachment" }
    , { "background-clip", "Origin" }
    , { "background-origin", "Origin" }
    , { "border", "Border" }
    , { "border-top", "Border" }
    , { "border-right", "Border" }
    , { "border-bottom", "Border" }
    , { "border-left", "Border" }
    , { "border-color", "Box Colors" }
    , { "border-top-color", "Brush" }
    , { "border-right-color", "Brush" }
    , { "border-bottom-color", "Brush" }
    , { "border-left-color", "Brush" }
    , { "border-image", "Border Image" }
    , { "border-radius", "Radius" }
    , { "border-top-left-radius", "Radius" }
    , { "border-top-right-radius", "Radius" }
    , { "border-bottom-right-radius", "Radius" }
    , { "border-bottom-left-radius", "Radius" }
    , { "border-style", "Border Style" }
    , { "border-top-style", "Border Style" }
    , { "border-right-style", "Border Style" }
    , { "border-bottom-style", "Border Style" }
    , { "border-left-style", "Border Style" }
    , { "border-width", "Box Lengths" }
    , { "border-top-width", "Length" }
    , { "border-right-width", "Length" }
    , { "border-bottom-width", "Length" }
    , { "border-left-width", "Length" }
    , { "bottom", "Length" }
    , { "button-layout", "Number" }
    , { "color", "Brush" }
    , { "dialogbuttonbox-buttons-have-icons", "Boolean" }
    , { "font", "Font" }
    , { "font-family", "String" }
    , { "font-size", "Font Size" }
    , { "font-style", "Font Style" }
    , { "font-weight", "Font Weight" }
    , { "gridline-color", "Color" }
    , { "height", "Length" }
    , { "icon-size", "Length" }
    , { "image", "Url" }
    , { "image-position", "Alignment" }
    , { "left", "Length" }
    , { "lineedit-password-character", "Number" }
    , { "lineedit-password-mask-delay", "Number" }
    , { "margin", "Box Lengths" }
    , { "margin-top", "Length" }
    , { "margin-right", "Length" }
    , { "margin-bottom", "Length" }
    , { "margin-left", "Length" }
    , { "max-height", "Length" }
    , { "max-width", "Length" }
    , { "messagebox-text-interaction-flags", "Number" }
    , { "min-height", "Length" }
    , { "min-width", "Length" }
    , { "opacity", "Number" }
    , { "outline", " " }
    , { "outline-color", "Color" }
    , { "outline-offset", "Length" }
    , { "outline-style", " " }
    , { "outline-radius", " " }
    , { "outline-bottom-left-radius", "Radius" }
    , { "outline-bottom-right-radius", "Radius" }
    , { "outline-top-left-radius", "Radius" }
    , { "outline-top-right-radius", "Radius" }
    , { "padding", "Box Lengths" }
    , { "padding-top", "Length" }
    , { "padding-right", "Length" }
    , { "padding-bottom", "Length" }
    , { "padding-left", "Length" }
    , { "paint-alternating-row-colors-for-empty-area", "bool" }
    , { "position", "Position" }
    , { "right", "Length" }
    , { "selection-background-color", "Brush" }
    , { "selection-color", "Brush" }
    , { "show-decoration-selected", "Boolean" }
    , { "spacing", "Length" }
    , { "subcontrol-origin", "Origin" }
    , { "subcontrol-position", "Alignment" }
    , { "titlebar-show-tooltips-on-buttons}", "bool" }
    , { "widget-animation-duration", "Number" }
    , { "text-align", "Alignment" }
    , { "text-decoration", "Text Decoration" }
    , { "top", "Length" }
    , { "width", "Length" }
};

QVector<QString> Keywords::ListOfIcons = {
    "backward-icon"
    , "cd-icon"
    , "computer-icon"
    , "desktop-icon"
    , "dialog-apply-icon"
    , "dialog-cancel-icon"
    , "dialog-close-icon"
    , "dialog-discard-icon"
    , "dialog-help-icon"
    , "dialog-no-icon"
    , "dialog-ok-icon"
    , "dialog-open-icon"
    , "dialog-reset-icon"
    , "dialog-save-icon"
    , "dialog-yes-icon"
    , "directory-closed-icon"
    , "directory-icon"
    , "directory-link-icon"
    , "directory-open-icon"
    , "dockwidget-close-icon"
    , "downarrow-icon"
    , "dvd-icon"
    , "file-icon"
    , "file-link-icon"
    , "filedialog-contentsview-icon"
    , "filedialog-detailedview-icon"
    , "filedialog-end-icon"
    , "filedialog-infoview-icon"
    , "filedialog-listview-icon"
    , "filedialog-new-directory-icon"
    , "filedialog-parent-directory-icon"
    , "filedialog-start-icon"
    , "floppy-icon"
    , "forward-icon"
    , "harddisk-icon"
    , "home-icon"
    , "leftarrow-icon"
    , "messagebox-critical-icon"
    , "messagebox-information-icon"
    , "messagebox-question-icon"
    , "messagebox-warning-icon"
    , "network-icon"
    , "rightarrow-icon"
    , "titlebar-contexthelp-icon"
    , "titlebar-maximize-icon"
    , "titlebar-menu-icon"
    , "titlebar-minimize-icon"
    , "titlebar-normal-icon"
    , "titlebar-shade-icon"
    , "titlebar-unshade-icon"
    , "trash-icon"
    , "uparrow-icon"
};

QMap<QString, QVector<QString>> Keywords::MapOfPropertyTypes {
    { "Alignment", {"top", "bottom", "left", "right", "center"} }
  , { "Attachment", {"scroll", "fixed"} }
  , { "Background", {"Brush", "Url", "Repeat", "Alignment"} }
  , { "Boolean", {"0", "1"} }
  , { "Border", {"Border Style", "Length", "Brush"} }
  , { "Border Image", {"none", "Url", "Number", "stretch", "repeat"} }
  , { "Border Style", {"dashed", "dot-dash", "dot-dot-dash", "dotted", "groove", "inset", "outset", "ridge", "solid", "none"} }
  , { "Box Colors", {"Brush"} }
  , { "Box Lengths", {"Length"} }
  , { "Brush", {"Color", "Gradient", "PaletteRole"} }
  , { "Color", {"rgb(r, g, b)", "rgba(r, g, b, a)", "hsv(h, s, v)", "hsva(h, s, v, a)", "#rrggbb", "Color Name"} }
  , { "Color Name", {"white", "black", "red", "darkRed", "green", "darkGreen", "blue", "darkBlue", "cyan", "darkCyan", "magenta", "darkMagenta", "yellow", "darkYellow", "gray", "darkGray", "lightGray", "transparent"} }
  , { "Font", {"Font Style", "Font Weight", "Font", "Size", "String"} }
  , { "Font Size", {"Length"} }
  , { "Font Style", {"normal", "italic", "oblique"} }
  , { "Font Weight", {"normal", "bold", "100", "200", "900"} }
  , { "Gradient", {"qlineargradient", "qradialgradient", "qconicalgradient"} }
  , { "Icon", {"Url", "disabled", "active", "normal", "selected", "on", "off"} }
  , { "Length", {"Number", "px", "pt", "em", "ex"} }
  , { "Number", {" "} }
  , { "Origin", {"margin", "border", "padding", "content"} }
  , { "PaletteRole", {"alternate-base", "base", "bright-text", "button", "button-text", "dark", "highlight", "highlighted-text", "light", "link", "link-visited", "mid", "midlight", "shadow", "text", "window", "window-text"} }
  , { "Position", {"relative", "absolute"} }
  , { "Radius", {"Length"} }
  , { "Repeat", {"repeat-x", "repeat-y", "repeat", "no-repeat"} }
  , { "Text Decoration", {"none", "underline", "overline", "line-through"} }
  , { "Url", {"url(filename)"} }
};

QVector<QString> Keywords::ListOfPseudoStates = {
    "active"
    , "adjoins-item"
    , "alternate"
    , "bottom"
    , "checked"
    , "closable"
    , "closed"
    , "default"
    , "disabled"
    , "editable"
    , "edit-focus"
    , "enabled"
    , "exclusive"
    , "first"
    , "flat"
    , "floatable"
    , "focus"
    , "has-children"
    , "has-siblings"
    , "horizontal"
    , "hover"
    , "indeterminate"
    , "last"
    , "left"
    , "maximized"
    , "middle"
    , "minimized"
    , "movable"
    , "no-frame"
    , "non-exclusive"
    , "off"
    , "on"
    , "only-one"
    , "open"
    , "next-selected"
    , "pressed"
    , "previous-selected"
    , "read-only"
    , "right"
    , "selected"
    , "top"
    , "unchecked"
    , "vertical"
    , "window"
};

QVector<QString> Keywords::ListOfSubControls {
    "add-line"
    , "add-page"
    , "branch"
    , "chunk"
    , "close-button"
    , "corner"
    , "down-arrow"
    , "down-button"
    , "drop-down"
    , "float-button"
    , "groove"
    , "indicator"
    , "handle"
    , "icon"
    , "item"
    , "left-arrow"
    , "left-corner"
    , "menu-arrow"
    , "menu-button"
    , "menu-indicator"
    , "right-arrow"
    , "pane"
    , "right-corner"
    , "scroller"
    , "section"
    , "separator"
    , "sub-line"
    , "sub-page"
    , "tab"
    , "tab-bar"
    , "tear"
    , "tearoff"
    , "text"
    , "title"
    , "up-arrow"
    , "up-button"
};

QChar Keywords::ListOfIdentifiers[4] {
    '}', ';', '{', ':'
};

Keywords::Keywords(QObject *parent) : QAbstractListModel(parent)
{

}

bool Keywords::getFromPropertyType(const QString type, QStringList &out, int deep)
{
    if (MapOfPropertyTypes.find(type)==MapOfPropertyTypes.end()) {
        qDebug() << "ListOfPropertyTypes jest prawdopodobnie niekompletny";
        return false;
    }

    for (QVector<QString>::const_iterator s=MapOfPropertyTypes[type].begin();
         s!=MapOfPropertyTypes[type].end(); s++) {
        if(s->at(0).isUpper()) {
            getFromPropertyType(*s, out, deep+1);
        } else {
            out.push_back(*s);
        }
    }

    if (!deep)
        qSort(out);
}

QVariant Keywords::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        if (index.row()>-1 && index.row()<mList.count())
            return mList[index.row()];
    }
    return QVariant();
}

int Keywords::rowCount(const QModelIndex &parent) const
{
    return mList.count();
}

void Keywords::isDoubleClicked(const QModelIndex &index)
{
    if (index.row()>-1 && index.row()<mList.count())
        emit doubleClicked( mList[index.row()] );
}

void Keywords::isClicked(const QModelIndex &index)
{
    emit clicked(true);
}

bool removeFromQStringListMismatched(QList<QString> &inOut, const QString prefix)
{
    for (QList<QString>::iterator it=inOut.begin(); it!=inOut.end(); ) {
        QString tmp = it->mid(0, prefix.length());
        if (tmp.compare(prefix)!=0) {
            it = inOut.erase(it);
        } else
            it++;
    }
}
