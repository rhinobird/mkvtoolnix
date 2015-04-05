#ifndef MTX_MKVTOOLNIX_GUI_CHAPTER_EDITOR_TOOL_H
#define MTX_MKVTOOLNIX_GUI_CHAPTER_EDITOR_TOOL_H

#include "common/common_pch.h"

#include "mkvtoolnix-gui/main_window/tool_base.h"

class QDragEnterEvent;
class QDropEvent;
class QMenu;

namespace mtx { namespace gui { namespace ChapterEditor {

namespace Ui {
class Tool;
}

class Tab;

class Tool : public ToolBase {
  Q_OBJECT;

protected:
  // UI stuff:
  std::unique_ptr<Ui::Tool> ui;
  QMenu *m_chapterEditorMenu;
public:
  explicit Tool(QWidget *parent, QMenu *chapterEditorMenu);
  ~Tool();

  virtual void retranslateUi() override;

  // virtual void dragEnterEvent(QDragEnterEvent *event) override;
  // virtual void dropEvent(QDropEvent *event) override;

public slots:
  virtual void toolShown() override;
  virtual void tabTitleChanged(QString const &title);
  virtual void newFile();
  virtual void selectFileToOpen();
  // virtual void save();
  // virtual void validate();
  virtual void closeTab(int index);
  virtual void closeCurrentTab();
  virtual void closeSendingTab();
  // virtual void reload();

protected:
  Tab * appendTab(Tab *tab);

  virtual void openFile(QString const &fileName);
  virtual void setupMenu();
  virtual void showChapterEditorsWidget();
  virtual Tab *currentTab();
};

}}}

#endif // MTX_MKVTOOLNIX_GUI_CHAPTER_EDITOR_TOOL_H
