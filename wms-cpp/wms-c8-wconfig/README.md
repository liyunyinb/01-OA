# ʾ��ģ��

## ���
�ܹ�ʹ��ʾ����Ŀ��

## Ŀ¼�ṹ˵��
> `arch-demo`
>
> > `conf` -- Windowsƽ̨��Ҫ�������ļ�
> >
> > `controller` -- `MVC`��Controllerʵ�֣����ڽ����û�����
> >
> > `service` -- ҵ���߼������
> >
> > `dao` -- ���ݿ���ʲ�
> >
> > `domain`  -- ����ģ��ʵ��
> >
> > `public` -- ���Է�����ҳ����
> >
> > `CMakeLists.txt` -- `Cmake`��ƽ̨���������ļ�
> >
> > `Macros.h` -- ͨ�ú궨��
> >
> > `ServerInfo.h` -- ��������Ϣ���浥��
> >
> > `stdafx.h` -- Ԥ�����ͷ�ļ�
> >
> > `main.cpp` -- �������
> >
> > `public.pem` -- `RSA`��Կ
> >
> > `zh-dict.yaml` -- ���Ĵʵ�����

## �������ݿ��

�����ݿ��д���һ��sample�����ڲ��ԡ�

```sql
DROP TABLE IF EXISTS `sample`;
CREATE TABLE `sample` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(50) DEFAULT NULL,
  `sex` char(1) DEFAULT NULL,
  `age` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
```

## ���������淶

- `Controller/Service/DAO` �㷽��������Լ
  - ��ȡ��������ķ����� `query/get/select` ��ǰ׺��
  - ��ȡ�������ķ����� `query/list/select` ��ǰ׺��
  - ��ȡͳ��ֵ�ķ����� `count/count/count` ��ǰ׺��
  - ����ķ����� `add/save/insert` ��ǰ׺��
  - ɾ���ķ����� `remove/remove/delete` ��ǰ׺��
  - �޸ĵķ����� `modify/update/update` ��ǰ׺��
  - `Controller`ִ���߼�������ʹ��`exec`��ǰ׺��
    - ��ӿڶ˵㷽������Ϊ`queryByName`����Ӧ��ִ�з�������Ϊ`execQueryByName`��
  - `API`����·��������ǰ׺���磺����ģ�����ƣ�+ �������ƣ��������ʹ��-���ӣ������������ʾ����
    - `/sys/query-by-name`��`/user/add-user`��`/user/modify-password`��
- ����ģ��������Լ
  - DO��`xxxDO`��`xxx` ��Ϊ���ݱ�����
  - DTO��`xxxDTO`��`xxx` Ϊҵ��������ص����ơ�
  - Query��`xxxQuery`��`xxx`Ϊҵ��������ص����ơ�
  - VO��`xxxVO`��`xxx` һ��Ϊ��ҳ���ơ�
  - `POJO` �� `DO/DTO/BO/VO/Query` ��ͳ�ƣ���ֹ������ `xxxPOJO`��