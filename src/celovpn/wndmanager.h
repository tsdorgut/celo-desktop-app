/***************************************************************************
 *   Copyright (C) 2017 by Jeremy Whiting <jeremypwhiting@gmail.com>       *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.                *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/

#ifndef WNDMANAGER_H
#define WNDMANAGER_H

#include "common.h"

#include <QWidget>
#include <QDialog>
#include <memory>

#include "confirmationdialog.h"
#include "dlg_newnode.h"

//  WndManager::Instance()->ToPrimary(this);
//  WndManager::Instance()->HideThis(this);
//  WndManager::DoShape(this);
class WndManager: public QObject
{
    Q_OBJECT
public:
    static WndManager * Instance();
    ~WndManager();
    static void Cleanup();

    QWidget * Primary();
    void ToPrimary();
    void ToSettings();
    void ToLogs();
    void ToMap();

    void CloseAll();
    void HideThis(QWidget * scr);

    void trans(const QPoint & p, QWidget * to);
    QPoint CurrPos();
    void SavePos();
    QWidget * ScrVisible();	 // NULL if no visible

    static void DoShape(QWidget * d);

    void ToFront(QWidget * w);
    void ToFront();

    int Confirmation(const QString & msg);		// switch to primary, return dialog code: QDialog::Accepted or another

    void ClosePortDlg();
    bool IsCyclePort();		// true - if cycle ports; false - cycle nodes

private slots:
    void stateChanged(vpnState state);

    void showErrorMessage(const QString & msg);

    void showPortDialog();

private:
    WndManager();
    static std::auto_ptr<WndManager> _inst;
    void trans(QWidget * from, QWidget * to);

    void SaveCoords(QWidget * from);
    int _x;
    int _y;
    void ApplyCoords(QWidget * to);

    void ToLogin();
    void ToConnect();

    void SaveAndHide(QWidget * from);
    void DoTrans(QWidget * to);
    Dlg_newnode * _DlgPort;
};

#endif // WNDMANAGER_H
