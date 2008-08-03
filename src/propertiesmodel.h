/*
 * Tiled Map Editor (Qt)
 * Copyright 2008 Tiled (Qt) developers (see AUTHORS file)
 *
 * This file is part of Tiled (Qt).
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc., 59 Temple
 * Place, Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef PROPERTIESMODEL_H
#define PROPERTIESMODEL_H

#include <QAbstractItemModel>
#include <QList>
#include <QMap>
#include <QString>

namespace Tiled {
namespace Internal {

class PropertiesModel : public QAbstractTableModel
{
    public:
        /**
         * Constructor.
         */
        PropertiesModel(QObject *parent = 0);

        /**
         * Returns the number of rows.
         */
        int rowCount(const QModelIndex &parent = QModelIndex()) const;

        /**
         * Returns the number of columns.
         */
        int columnCount(const QModelIndex &parent = QModelIndex()) const;

        /**
         * Returns the data stored under the given <i>role</i> for the item
         * referred to by the <i>index</i>.
         */
        QVariant data(const QModelIndex &index,
                      int role = Qt::DisplayRole) const;

        /**
         * Returns the headers for the table.
         */
        QVariant headerData(int section, Qt::Orientation orientation,
                            int role = Qt::DisplayRole) const;

        /**
         * Sets the properties returned by this model.
         */
        void setProperties(QMap<QString, QString> properties);

    private:
        QMap<QString, QString> mProperties;
        QList<QString> mKeys;
};

} // namespace Internal
} // namespace Tiled

#endif // PROPERTIESMODEL_H