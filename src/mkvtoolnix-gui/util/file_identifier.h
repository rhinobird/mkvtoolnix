#ifndef MTX_MKVTOOLNIX_GUI_UTIL_FILE_IDENTIFIER_H
#define MTX_MKVTOOLNIX_GUI_UTIL_FILE_IDENTIFIER_H

#include "common/common_pch.h"

#include <QStringList>
#include <QVariant>

#include "mkvtoolnix-gui/merge/source_file.h"

namespace mtx { namespace gui { namespace Util {

class FileIdentifierPrivate;
class FileIdentifier: public QObject {
  Q_OBJECT;

protected:
  Q_DECLARE_PRIVATE(FileIdentifier);

  QScopedPointer<FileIdentifierPrivate> const d_ptr;

  explicit FileIdentifier(FileIdentifierPrivate &d);

public:
  FileIdentifier(QString const &fileName = QString{});
  virtual ~FileIdentifier();

  virtual bool identify();

  virtual QString const &fileName() const;
  virtual void setFileName(QString const &fileName);

  virtual int exitCode() const;
  virtual QStringList const &output() const;

  virtual mtx::gui::Merge::SourceFilePtr const &file() const;

  virtual QString const &errorTitle() const;
  virtual QString const &errorText() const;

public:
  static void addProbeRangePercentageArg(QStringList &args, double probeRangePercentage);

protected:
  virtual bool parseOutput();
  virtual void parseAttachment(QVariantMap const &obj);
  virtual void parseChapters(QVariantMap const &obj);
  virtual void parseContainer(QVariantMap const &obj);
  virtual void parseGlobalTags(QVariantMap const &obj);
  virtual void parseTrackTags(QVariantMap const &obj);
  virtual void parseTrack(QVariantMap const &obj);

  virtual void setError(QString const &errorTitle, QString const &errorText);
};

}}}

#endif // MTX_MKVTOOLNIX_GUI_UTIL_FILE_IDENTIFIER_H
